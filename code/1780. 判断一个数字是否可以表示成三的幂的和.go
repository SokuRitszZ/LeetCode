func checkPowersOfThree(n int) bool {
    for n > 1 {
        if n % 3 == 0 {
            n /= 3
        } else if (n - 1) % 3 == 0 {
            n = (n - 1) / 3;
        } else {
            return false
        }
    }
    return true
}