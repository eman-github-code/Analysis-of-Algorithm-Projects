def dfs_all_paths(graph, src, dest):
    src = src.upper()
    dest = dest.upper()
    all_paths = []

    def dfs(current, path, visited):
        if current == dest:
            all_paths.append(path.copy())
            return
        for neighbor in graph.get(current, []):
            if neighbor in visited:
                continue
            visited.add(neighbor)
            path.append(neighbor)
            dfs(neighbor, path, visited)
            path.pop()
            visited.remove(neighbor)

    if src in graph and dest in graph:
        dfs(src, [src], {src})
    return all_paths
