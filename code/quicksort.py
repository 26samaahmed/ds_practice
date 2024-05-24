# Quick Sort and Partition
A = [10, 16, 8, 12, 15, 6, 3, 9, 5]
def partition(l, h, A):
  pivot = A[l]
  i, j = l, h
  while i < j:
    # make sure to check boundaries
    while i <= h and A[i] <= pivot:
      i += 1
    while j >= l and A[j] > pivot:
      j -= 1

    # if i < j after the inner loops, then swap the values at i and j
    if i < j:
      A[i], A[j] = A[j], A[i]

  # swap the pivot with the value at index j
  A[l], A[j] = A[j], A[l]
  return j # index of the pivot

def quickSort(l, h, A):
  # check that there are at least 2 elements in the list
  if l < h:
    j = partition(l, h, A)
    # partition the subarrays. We use j - 1 and j + 1 because we don't want to modify j which is the pivot value. We sort what's below and above the pivot only
    quickSort(l, j - 1, A) # left part of the list
    quickSort(j + 1, h, A) # right part of the list

quickSort(0, len(A) - 1, A)
print(A)