func beautySum(s string) int {
	res := 0
	for i := range s {
		cnt := [26]int{}
		mxF := 0 
		for _, c := range s[i:] {
			cnt[c - 'a']++
			mxF = max(mxF, cnt[c - 'a'])
			mnF := len(s)
			for _, c := range cnt {
				if c > 0 {
					mnF = min(mnF, c)
				}
			}
			res += mxF - mnF
		}
	}
	return res
}

func min(a int, b int) int {if a < b {return a}; return b}

func max(a int, b int) int {if a > b {return a}; return b}