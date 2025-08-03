import os, sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.bfs import bfs_shortest_path
from src.bfs import bfs_shortest_path
from src.dfs import dfs_all_paths

graph = {
    "A": ["B", "C"],
    "B": ["C", "D"],
    "C": ["D"],
    "D": []
}

def test_bfs():
    assert bfs_shortest_path(graph, "A", "D") == ["A", "B", "D"]

def test_dfs():
    paths = dfs_all_paths(graph, "A", "D")
    expected = [
        ["A", "B", "D"],
        ["A", "B", "C", "D"],
        ["A", "C", "D"],
    ]
    assert sorted(paths) == sorted(expected)

if __name__ == "__main__":
    test_bfs()
    test_dfs()
    print("All tests passed.")
