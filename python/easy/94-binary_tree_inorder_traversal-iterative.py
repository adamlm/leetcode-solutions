# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        values = []
        to_visit = []
        node = root
        while node is not None or to_visit:
            while node is not None:
                to_visit.append(node)
                node = node.left

            node = to_visit.pop()
            values.append(node.val)
            node = node.right

        return values

