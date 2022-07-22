from enum import unique


def test(inputs, truth, func, verbose = True, execute_only = -1):
    if execute_only != -1:
        output = func(inputs[execute_only])
        if truth[execute_only] != output:
            if verbose:
                print(f"Test {execute_only + 1}:\nExp:\t{str(truth[execute_only])}\nGot:\t{str(output)}")
        else:
            if verbose:
                print(f"Test {execute_only + 1} is correct")

    else:
        for i in range(len(inputs)):
            output = func(inputs[i])
            if truth[i] != output:
                if verbose:
                    print(f"Test {i + 1}:\nExp:\t{str(truth[i])}\nGot:\t{str(output)}")
            else:
                if verbose:
                    print(f"Test {i + 1} is correct")

class Solution:
    def leastInterval(self, tasks: list[str], n: int) -> int:
        num_tasks = {}
        last_executed_idx = {}
        for task in tasks:
            if task not in num_tasks:
                last_executed_idx[task] = -1
                num_tasks[task] = 1
            else:
                num_tasks[task] += 1

        remaining_tasks = list(num_tasks.keys())
        remaining_tasks.sort(key=lambda s : num_tasks[s], reverse=True)

        tasks_to_execute = len(tasks)
        
        IDLE = "idle"
        ans = []

        while tasks_to_execute != 0:
            added_task = False
            
            for task in remaining_tasks:
                if num_tasks[task] > 0:
                    if last_executed_idx[task] == -1 or (n < len(ans) - last_executed_idx[task]):
                        last_executed_idx[task] = len(ans)
                        num_tasks[task] -= 1
                        remaining_tasks.sort(key=lambda s : num_tasks[s], reverse=True)
                        ans.append(task)
                        added_task = True
                        break

            if not added_task:
                ans.append(IDLE)
            else:
                tasks_to_execute -= 1
                
        print(ans)
        return len(ans)

def adapter(item):
    _ = Solution()
    return _.leastInterval(item[0], item[1])

inputs = [[["A","A","A","B","B","B"], 2], [["A","A","A","B","B","B"], 0], [["A","A","A","A","A","A","B","C","D","E","F","G"], 2], [["A","A","A","B","B","B","C","C","C","D","D","E"], 2]]
outputs = [8, 6, 16, 12]
test(inputs, outputs, adapter)


