import heapq

def minRefuelStops(target, startFuel, stations):
    max_heap = []  # Max heap to store available fuel at each station
    stops = 0
    curr_pos = startFuel

    for pos, fuel in stations:
        while max_heap and curr_pos < pos:
            curr_pos += -heapq.heappop(max_heap)
            stops += 1
        if curr_pos < pos:
            return -1
        heapq.heappush(max_heap, -fuel)

    while max_heap and curr_pos < target:
        curr_pos += -heapq.heappop(max_heap)
        stops += 1

    return stops if curr_pos >= target else -1

target = 100
startFuel = 10
stations = [[10, 60], [20, 30], [30, 30], [60, 40]]
print("Minimum refueling stops:", minRefuelStops(target, startFuel, stations))
