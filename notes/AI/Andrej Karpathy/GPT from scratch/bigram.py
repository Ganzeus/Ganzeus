import torch
import torch.nn as nn
from torch.nn import functional as F

# hyperparameters
batch_size = 32
block_size = 8
max_iters = 3000
eval_interval = 300
learning_rate = 1e-2
device = 'cuda:7' if torch.cuda.is_available() else 'cpu'
eval_iters = 200

torch.manual_seed(1337)

# !wget https://raw.githubusercontent.com/karpathy/char-rnn/master/data/tinyshakespeare/input.txt
with open('input.txt', 'r', encoding='utf-8') as f:
    text = f.read()

# 统计出现的字符种类
chars = sorted(list(set(text)))     # 集合->列表->排序
vocab_size = len(chars)

stoi = {ch:i for i, ch in enumerate(chars)}
itos = {i:ch for i, ch in enumerate(chars)}
encode = lambda s: [stoi[c] for c in s]           # 编码器：将字符串转换为编号的函数
decode = lambda l: ''.join([itos[i] for i in l])  # 解码器：将编号转换为字符串的函数

# train and test splits
data = torch.tensor(encode(text), dtype = torch.long)   # 编码整个数据集
n = int(0.9*len(data))   # train size(90%)
train_data = data[:n]
valid_data = data[n:]

# data loading
def get_batch(split):   # 从所选数据集提取batch split='train' or 'valid'
    # generate a small batch of data of inputs x and target y
    data = train_data if split == 'train' else valid_data
    ix = torch.randint(len(data) - block_size, (batch_size,))   # 从[0, len(data)-block_size]中随机挑选batch_size个整数，组成一个向量
                                                                # 作用：ix就是一个batch中各个向量的起始下标，len(data)-block_size是为了防越界
    x = torch.stack([data[i:i+block_size] for i in ix])         # 将batch_size个长为block_size的向量堆叠，形成(batch_size, block_size)的Tensor
    y = torch.stack([data[i+1:i+block_size+1] for i in ix])     # 堆叠形成(batch_size, block_size)的Tensor,但数据需要向后移动一格
    
    x, y = x.to(device), y.to(device)

    return x, y     # 返回 (value, target)

@torch.no_grad()
def estimate_loss():
    out = {}
    model.eval()
    for split in ['train', 'val']:      # 分别计算training loss 和 validation loss
        losses = torch.zeros(eval_iters)
        for k in range(eval_iters):
            X, Y = get_batch(split)
            logits, loss = model(X, Y)
            losses[k] = loss.item()
        out[split] = losses.mean()      # 计算平均loss
    model.train()
    return out

# simple bigram model
class BigramLanguageModel(nn.Module):
    def __init__(self):
        super().__init__()
        # 创建embedding table, 每个词(token)对应一个向量, 字典中的每个词都有对应的向量
        self.token_embedding_table = nn.Embedding(vocab_size, vocab_size)

    def forward(self, idx, targets=None):
        # 查表, 将词转换为向量（传入idx下标）, 查表得到的向量就是根据当前词所作出的预测结果
        logits = self.token_embedding_table(idx)    # (batch, time, channel)
        
        if targets is None:
            loss = None
        else:
            B, T, C = logits.shape
            logits = logits.view(B*T, C)    # 修改shape, 方便送入cross_entropy
            targets = targets.view(B*T)     
            loss = F.cross_entropy(logits, targets)

        
        return logits, loss
    
    def generate(self, idx, max_new_tokens):    # max_new_tokens表示需要生成多少词
        # idx is (B, T) tensor, 存放当前上下文的标签
        for _ in range(max_new_tokens):
            # 预测结果
            logits, loss = self(idx)
            # 提取最后一个预测，即下一个词的预测结果
            logits = logits[:, -1, :]   # (B, C)
            # apply softmax to get probabilities
            probs = F.softmax(logits, dim=-1)   # (B, C)
            # sample from the distribution
            idx_next = torch.multinomial(probs, num_samples=1)  # 从预测的概率中随机选一个，不是直接选概率最高的那个词
            # append sampled idx to the running sequence
            idx = torch.cat((idx, idx_next), dim=1) # (B, T+1)
        return idx  
    


model = BigramLanguageModel()
m = model.to(device)

# create optimizer
optimizer = torch.optim.AdamW(model.parameters(), lr = learning_rate)

for iter in range(max_iters):

    # 每个eval_interval轮,输出loss
    if iter % eval_interval == 0:
        losses = estimate_loss()
        print(f"step {iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}")

    # sample a batch of data
    xb, yb = get_batch('train')

    # evaluate the loss
    logits, loss = m(xb, yb)
    optimizer.zero_grad(set_to_none=True)
    loss.backward()
    optimizer.step() 

# generate from the model
context = torch.zeros((1, 1), dtype=torch.long, device=device)
print(decode(m.generate(context, max_new_tokens=500)[0].tolist()))