# Sliding window is the proceedure of moving a window of fixed size over the input data.
# We can have either a fixed window size or a variable window size.
# This is how I think it could work

# lets say i have an array of [1, 2, 3, 4, 5, 6] and i want to find the biggest sum for sub array with size 3
def sliding_window(arr, k):
  window_sum = sum(arr[:k])
  max_sum = window_sum
  # Loop through the array
  # the last possible starting of the window is n - k where n is the length of the array
  for i in range(len(arr) - k):
    window_sum = window_sum - arr[i] + arr[i + k]
    max_sum = max(window_sum, max_sum)
  return max_sum

print(sliding_window([1, 20, 3, 4, 5, 6], 2))