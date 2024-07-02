
#Problem Statement:- Write a program to implement Huffman Encoding using a greedy strategy.

import heapq
class node:
	def __init__(self, freq, symbol, left=None, right=None):
		self.freq = freq
		self.symbol = symbol
		self.left = left
		self.right = right
		self.huff = ''

	def __lt__(self, nxt):
		return self.freq < nxt.freq

def printNodes(node, val=''):

	newVal = val + str(node.huff)
	if(node.left):
		printNodes(node.left, newVal)
	if(node.right):
		printNodes(node.right, newVal)
	
	if(not node.left and not node.right):
		print(f"{node.symbol} -> {newVal}")

chars = []
freq = []
n = int(input("Enter a number of inputs: "))
for i in range(n):
    ch=input("enter character:")
    chars.append(ch)
    cha=int(input("Enter Frequency:"))
    freq.append(cha)
print(chars , freq)

nodes = []
for x in range(len(chars)):
	heapq.heappush(nodes, node(freq[x], chars[x]))

while len(nodes) > 1:

	left = heapq.heappop(nodes)
	right = heapq.heappop(nodes)

	left.huff = 0
	right.huff = 1
	
	newNode = node(left.freq+right.freq, left.symbol+right.symbol, left, right)

	heapq.heappush(nodes, newNode)
printNodes(nodes[0])



""" Output:
Enter a number of inputs: 5
enter character:M
Enter Frequency:6
enter character:o
Enter Frequency:3
enter character:h
Enter Frequency:8
enter character:a
Enter Frequency:1
enter character:n
Enter Frequency:5
['M', 'o', 'h', 'a', 'n'] [6, 3, 8, 1, 5]
a -> 000
o -> 001
n -> 01
M -> 10
h -> 11

"""
