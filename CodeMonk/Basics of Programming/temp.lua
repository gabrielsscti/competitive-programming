n = io.read("*n")
ans = 1
for i=1, n do
    temp = io.read("*n")
    ans = (ans*temp) % ((10^9)+8);
end
print(ans)
