# Let’s say, you are going to spend a month in the wilderness. Only thing you are carrying is the
# backpack which can hold a maximum weight of 40 kg. Now you have different survival items, each
# having its own “Survival Points” (which are given for each item in the table). Some of the items are so
# essential that if you do not take them, you incur some additional penalty.

# Here is the table giving details about each item.
# Item Weight Survival Value Penalty if not taken
# Sleeping Bag 30 20 0
# Rope 10 10 0
# Bottle 5 20 0
# Torch+Battery 15 25 -20
# Glucose 5 30 0
# Pocket Knife 10 15 -10
# Umbrella 20 10 0

# Let’s say, you are going to spend a month in the wilderness. Only thing you are carrying is the
# backpack which can hold a maximum weight of 40 kg. Now you have different survival items, each
# having its own “Survival Points” (which are given for each item in the table). Some of the items are so
# essential that if you do not take them, you incur some additional penalty.
import random
import fileinput
import numpy as np


def generate_total_samples():
    total_samples = []
    for i in range(0, n**2):
        total_samples.append(generate_one_sample())
    return total_samples


def generate_one_sample():
    sample = []
    for i in range(0, n):
        # generate random number between 0 and 1
        r = random.random()
        if r < 0.5:
            sample.append(0)
        else:
            sample.append(1)
    return sample


def fitness_calculation(sample):
    fitness_value = 0
    sum_weights = 0
    for i in range(0, n):
        if sample[i] == 1:
            fitness_value += survival_points[i]
            sum_weights += weights[i]

    if sum_weights > capacity:
        return 0

    # if we have not taken the item which has penalty then subtract that penalty from fitness_value
    for i in range(0,n):
        if sample[i] == 0 and penalty_points[i] != 0:
            fitness_value -= penalty_points[i]
    
    if fitness_value>0:
        return fitness_value
    else:
        return 0


def selection(sample, probability):
    # select 2n items from the n**2 items with the given probability
    selected_items = []
    selected = np.random.choice(sample, size=2*n, replace=True, p=probability)
    temp = selected.tolist()
    for i in range(0, 2*n):
        selected_items.append(total_samples[temp[i]])
    return selected_items


def crossover(sample1, sample2):
    # crossover the selected items
    crossover_point = random.randint(0, n-1)
    sample1_new = sample1[:crossover_point] + sample2[crossover_point:]
    sample2_new = sample2[:crossover_point] + sample1[crossover_point:]
    return sample1_new, sample2_new


def mutation(sample):
    # mutate the selected items
    mutation_point = random.randint(0, n-1)
    if sample[mutation_point] == 1:
        sample[mutation_point] = 0
    else:
        sample[mutation_point] = 1
    return sample


capacity = int(input("capacity of backpack: "))
n = int(input("Enter the number of items: "))
# create list to hold the items that are to be taken
items = []
# create list to hold the weights of the items
weights = []
# create list to hold the survival points of the items
survival_points = []
# create list to hold the penalty points of the items
penalty_points = []
# create list to hold the total survival points
total_survival_points = 0
# create list to hold the total penalty points
total_penalty_points = 0
# for i in range(0,n):
#     items.append(input("Enter the item name: "))
#     weights.append(int(input("Enter the weight of the item: ")))
#     survival_points.append(int(input("Enter the survival points of the item: ")))
#     penalty_points.append(int(input("Enter the penalty points of the item: ")))

# take input items, weights, survival_points, penalty_points from input.txt file
for line in fileinput.input(files='input.txt'):
    line = line.split()
    items.append(line[0])
    weights.append(int(line[1]))
    survival_points.append(int(line[2]))
    penalty_points.append(int(line[3]))

for i in range(len(survival_points)):
    total_survival_points += survival_points[i]

for i in range(len(penalty_points)):
    total_penalty_points += penalty_points[i]

# calculate the total_weights
total_weights = sum(weights)

total_samples = []
total_samples = generate_total_samples()

for i in range(len(total_samples)):
    print(total_samples[i])

population_fitness = 0
fitness_values = []
for i in range(len(total_samples)):
    fitness_values.append(fitness_calculation(total_samples[i]))
    population_fitness += fitness_calculation(total_samples[i])

# print the fitness_values
print("Fitness values: ", fitness_values)

probability = []
for i in range(len(total_samples)):
    probability.append(fitness_values[i]/population_fitness)

# for i in range(len(total_samples)):
#     print(probability[i])

# create sample array which contains values from 0 to n**2-1
selected_sample = []
for i in range(0, n**2):
    selected_sample.append(i)

# select 2n items from the n**2 items with the given probability
selected_items = selection(selected_sample, probability)

for i in range(len(selected_items)):
    print(selected_items[i])

fitness = []
for i in range(0, len(selected_items)):
    fitness.append(fitness_calculation(selected_items[i]))

prev_avg = 0.0
current_avg = 1.0
after_crossover = []

loop_counter = 0

# run an infinite loop
while abs(prev_avg-current_avg) > 0.00001:
    # calculate the fitness values of the selected items
    if loop_counter > 500:
        break

    prev_avg = current_avg

    # calculate the current average of the fitness
    current_avg = 0.0
    for i in range(0, len(fitness)):
        current_avg += fitness[i]
    current_avg = current_avg/len(fitness)

    # crossover the selected items
    # create n pairs of samples and do crossover
    for i in range(0, n):
        sample1 = selected_items[i]
        sample2 = selected_items[i+n]
        sample1_new, sample2_new = crossover(sample1, sample2)
        after_crossover.append(sample1_new)
        after_crossover.append(sample2_new)

    for i in range(0, len(after_crossover)):
        # mutate the selected items
        after_crossover[i] = mutation(after_crossover[i])

    fitness = []
    for i in range(0, len(after_crossover)):
        # calculate the fitness of the new samples
        fitness.append(fitness_calculation(after_crossover[i]))
    loop_counter += 1
    print(f"Epochs: {loop_counter}")
    # print the fitness values
    # print(f"\nFitness values after {loop_counter} iterations: {fitness}")

answer = []
# assign the after_crossover samples which has the maximum fitness_value to answer
for i in range(0, len(after_crossover)):
    if fitness[i] == max(fitness):
        answer = after_crossover[i]

# Print the answer
print("\n\nThe optimal solution according to Genetic Algorithm is: \n")
for i in range(0, n):
    if answer[i] == 1:
        print(items[i])

# total weight carrying in the backpack
weight_carrying, optimal_survival_points = 0,0
for i in range(0, n):
    if answer[i] == 1:
        weight_carrying += weights[i]
        optimal_survival_points += survival_points[i]

print(f"\nThe total weight carrying in the backpack is: {weight_carrying} and the total survival points is: {optimal_survival_points}")
