from graph_loader import load_graph_from_csv
from bfs import bfs_shortest_path
from dfs import dfs_all_paths
import os

def flight_route_checker(graph):
    src = input("Enter source airport: ").strip().upper()
    dest = input("Enter destination airport: ").strip().upper()

    if src not in graph:
        print(f"Source '{src}' not found in routes.")
        return
    if dest not in graph:
        print(f"Destination '{dest}' not found in routes.")
        return

    shortest = bfs_shortest_path(graph, src, dest)
    if shortest:
        stops = len(shortest) - 1
        print(f"\nBFS: Shortest route: {' -> '.join(shortest)} (stops: {stops})")
    else:
        print(f"\nBFS: No route from {src} to {dest}.")

    all_paths = dfs_all_paths(graph, src, dest)
    print(f"\nDFS: All possible routes from {src} to {dest}:")
    if not all_paths:
        print("  (none)")
    else:
        for i, path in enumerate(all_paths, 1):
            print(f"  {i}. {' -> '.join(path)} (stops: {len(path)-1})")

if __name__ == "__main__":
    # load from CSV if exists, otherwise use a fallback sample
    csv_path = os.path.join(os.path.dirname(__file__), "..", "flights.csv")
    if os.path.isfile(csv_path):
        graph = load_graph_from_csv(csv_path)
    else:
        graph = {
            "A": ["B", "C"],
            "B": ["C", "D"],
            "C": ["D"],
            "D": []
        }
    flight_route_checker(graph)
