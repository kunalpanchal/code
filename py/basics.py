# tuples
# tupples are immutable 
tup = 'python', 'geeks'
print(tup)
tup = ('python', 'geeks')
print(tup)
tup = ('python',)  # If the comma is not used it would be treated as a string instead of a tupple
print(tup)

# slicing
tuple1 = (0 ,1, 2, 3)
print(len(tuple1))
print(tuple1[1:])
print(tuple1[::-1])
print(tuple1[2:4])

if __name__ == "__main__":
    print('hello');