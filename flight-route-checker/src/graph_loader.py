import csv
from collections import defaultdict

def load_graph_from_csv(path):
    graph = defaultdict(list)
    with open(path, newline='') as f:
        reader = csv.DictReader(f)
        for row in reader:
            src = row["source"].strip().upper()
            dest = row["dest"].strip().upper()
            graph[src].append(dest)
            # if flights are bidirectional, also do:
            # graph[dest].append(src)
    return dict(graph)
