#!/usr/bin/python3
import sys
import itertools
from collections import deque


graph = {}

class Cave():
    def __init__(self, name):
        self.name = name
        self.ns = set()

def can_visit(name, path):
    if name == 'start':
        return False

    if name.isupper():
        return True

    d = {}
    for el in path:
        if not el.isupper():
            c = d.get(el, 0)
            d[el] = c + 1

    can_dv = True
    for el in d.values():
        if el > 1:
            can_dv = False

    count = d.get(name, 0)
    if count < 1:
        return True

    if can_dv:
        if count == 1:
            return True

    return False

def count_paths(currentNode, path):
    if currentNode.name == 'end':
        return 1
    
    paths = 0
    for n in currentNode.ns:
        if can_visit(n, path):
            paths += count_paths(graph[n], path + [n])
    
    return paths
            

infile = 'input.txt'
for line in open(infile):
    n1, n2 = line.strip().split('-')

    c1 = graph.get(n1, Cave(n1))
    c2 = graph.get(n2, Cave(n2))

    c1.ns.add(n2)
    c2.ns.add(n1)

    graph[n1] = c1
    graph[n2] = c2

print(count_paths(graph['start'], []))
