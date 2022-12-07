# Escape Pods
# ===========
# You've blown up the LAMBCHOP doomsday device and relieved the bunnies of their work duries -- and now you need to escape from the space station as quickly and as orderly as possible! The bunnies have all gathered in various locations throughout the station, and need to make their way towards the seemingly endless amount of escape pods positioned in other parts of the station. You need to get the numerous bunnies through the various rooms to the escape pods. Unfortunately, the corridors between the rooms can only fit so many bunnies at a time. What's more, many of the corridors were resized to accommodate the LAMBCHOP, so they vary in how many bunnies can move through them at a time.
# Given the starting room numbers of the groups of bunnies, the room numbers of the escape pods, and how many bunnies can fit through at a time in each direction of every corridor in between, figure out how many bunnies can safely make it to the escape pods at a time at peak.
# Write a function solution(entrances, exits, path) that takes an array of integers denoting where the groups of gathered bunnies are, an array of integers denoting where the escape pods are located, and an array of an array of integers of the corridors, returning the total number of bunnies that can get through at each time step as an int. The entrances and exits are disjoint and thus will never overlap. The path element path[A][B] = C describes that the corridor going from A to B can fit C bunnies at each time step. There are at most 50 rooms connected by the corridors and at most 2000000 bunnies that will fit at a time.
# For example, if you have:
# entrances = [0, 1]
# exits = [4, 5]
# path = [
# [0, 0, 4, 6, 0, 0], # Room 0: Bunnies
# [0, 0, 5, 2, 0, 0], # Room 1: Bunnies
# [0, 0, 0, 0, 4, 4], # Room 2: Intermediate room
# [0, 0, 0, 0, 6, 6], # Room 3: Intermediate room
# [0, 0, 0, 0, 0, 0], # Room 4: Escape pods
# [0, 0, 0, 0, 0, 0], # Room 5: Escape pods
# ]
# Then in each time step, the following might happen:
# 0 sends 4/4 bunnies to 2 and 6/6 bunnies to 3
# 1 sends 4/5 bunnies to 2 and 2/2 bunnies to 3
# 2 sends 4/4 bunnies to 4 and 4/4 bunnies to 5
# 3 sends 4/6 bunnies to 4 and 4/6 bunnies to 5

# So, in total, 16 bunnies could make it to the escape pods at 4 and 5 at each time step. (Note that in this example, room 3 could have sent any variation of 8 bunnies to 4 and 5, such as 2/6 and 6/6, but the final solution remains the same.)

def bfs(matrix, source, destination):
    visited = [-1 for i in range(len(matrix))]
    visited[source] = source
    queue = [source]
    while len(queue) > 0:
        top = queue.pop(0)
        for i in range(len(matrix)):
            if (matrix[top][i][1] - matrix[top][i][0]) != 0 and visited[i] == -1:
                if i == destination:
                    # Get route
                    visited[destination] = top
                    path = [destination]
                    temp = destination
                    while temp != source:
                        temp = visited[temp]
                        path.append(temp)
                    path.reverse()
                    # Get flow value and update augmented graph
                    temp = 1
                    total = float("inf")
                    cur = source
                    while temp != len(path):
                        entry = matrix[cur][path[temp]]
                        diff = abs(entry[1]) - entry[0]
                        total = min(total, diff)
                        cur = path[temp]
                        temp += 1
                    temp = 1
                    cur = source
                    while temp != len(path):
                        entry = matrix[cur][path[temp]]
                        if entry[1] < 0: # Already augmented need to flip
                            entry[1] += total
                        else:
                            entry[0] += total
                        entry = matrix[path[temp]][cur]
                        if entry[1] <= 0: # Already augmented need to flip
                            entry[1] -= total
                        else:
                            entry[0] += total
                        cur = path[temp]
                        temp += 1
                    return True
                else:
                    visited[i] = top
                    queue.append(i)
    return False

def solution(entrances, exits, path):
    max_val = sum(list(map(sum, path)))
    aug = []
    for i in range(len(path)):
        aug.append([])
        for j in range(len(path[i])):
            aug[i].append([0, path[i][j]])
        aug[i].append([0, 0])
        if i in exits:
            aug[i].append([0, max_val])
        else:
            aug[i].append([0, 0])
    aug.append([])
    aug.append([])
    for i in range(len(path[0]) + 2):
        if i in entrances:
            aug[-2].append([0, max_val])
        else:
            aug[-2].append([0, 0])
        aug[-1].append([0, 0])
    while bfs(aug, len(aug)-2, len(aug)-1):
        pass
    total = 0
    for i in range(len(aug)):
        total += aug[-2][i][0]
    return total

# Test cases
print(solution([0, 1], [4, 5], [[0, 0, 4, 6, 0, 0], [0, 0, 5, 2, 0, 0], [0, 0, 0, 0, 4, 4], [0, 0, 0, 0, 6, 6], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]))
print(solution([0], [3], [[0, 7, 0, 0], [0, 0, 6, 0], [0, 0, 0, 8], [9, 0, 0, 0]]))
