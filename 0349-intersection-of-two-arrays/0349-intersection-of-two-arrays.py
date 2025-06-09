class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        n1Set = set(nums1)
        n2Set = set(nums2)

        return list(n1Set.intersection(n2Set))
