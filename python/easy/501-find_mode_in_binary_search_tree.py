from collections import defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        counts = defaultdict(int)
        count_vals(root, counts)

        max_val = max(val for val in counts.values())
        modes = [key for key, val in counts.items() if val == max_val]

        return modes


def count_vals(root, counts):
    if root is None:
        return

    counts[root.val] += 1
    count_vals(root.left, counts)
    count_vals(root.right, counts)

