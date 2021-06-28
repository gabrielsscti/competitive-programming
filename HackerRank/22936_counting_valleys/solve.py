

n = int(input())
steps = str(input())
actHeight = 0
ans = 0

def process_step(step):
    global actHeight
    
    if step == 'U':
        actHeight += 1
    if step == 'D':
        actHeight -= 1

for step in steps:
    if actHeight == -1 and step == 'U': 
        ans += 1
    process_step(step)

print(ans)

