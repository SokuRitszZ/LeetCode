func checkIfPangram(sentence string) bool {
	vis := [26]bool{}
	res := 0
	for _, c := range sentence {
		if !vis[c - 'a'] {
			res++
		}
		vis[c - 'a'] = true
	}
	return res == 26
}