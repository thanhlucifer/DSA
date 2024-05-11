import heapq

def merge_k_sorted_arrays(matrix):
    merged = []
    pq = []  # Priority queue
    
    # Add the first element from each array to the priority queue
    for i in range(len(matrix)):
        heapq.heappush(pq, (matrix[i][0], i, 0))
    
    while pq:
        val, row, col = heapq.heappop(pq)
        merged.append(val)
        
        # Add the next element from the same row to the priority queue
        if col + 1 < len(matrix[row]):
            heapq.heappush(pq, (matrix[row][col + 1], row, col + 1))
    
    return merged

# Example usage
matrix = [[1, 3, 5], [2, 4, 6], [7, 8, 9]]
result = merge_k_sorted_arrays(matrix)
print("Merged array:", result)
