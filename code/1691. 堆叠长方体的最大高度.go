// https://leetcode.cn/problems/maximum-height-by-stacking-cuboids/solution/tu-jie-suan-fa-you-hua-xiang-xi-zheng-mi-b6fq/

func maxHeight(cuboids [][]int) (res int) {
	for _, c := range cuboids {
		sort.Ints(c)
	}
	sort.Slice(cuboids, func(i, j int) bool {
		a, b := cuboids[i], cuboids[j]
		return a[0] < b[0] || a[0] == b[0] && (a[1] < b[1] || a[1] == b[1] && a[2] < b[2])
	})
	f := make([]int, len(cuboids))
	for i, c2 := range cuboids {
		for j, c1 := range cuboids[:i] {
			if c1[1] <= c2[1] && c1[2] <= c2[2] {
				f[i] = max(f[i], f[j])
			}
		}
		f[i] += c2[2]
		res = max(res, f[i])
	}
	return 
}

func max(a, b int) int {if a < b {return b}; return a }