from collections import deque

def bfs_shortest_path(graph, src, dest):
    src = src.upper()
    dest = dest.upper()
    if src not in graph or dest not in graph:
        return None

    queue = deque([src])
    visited = {src}
    parent = {src: None}

    while queue:
        node = queue.popleft()
        if node == dest:
            path = []
            while node:
                path.append(node)
                node = parent[node]
            path.reverse()
            return path

        for neighbor in graph.get(node, []):
            if neighbor not in visited:
                visited.add(neighbor)
                parent[neighbor] = node
                queue.append(neighbor)
    return None
