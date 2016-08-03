/*
 * AngryProfessor.go
 * https://www.hackerrank.com/challenges/angry-professor
 *
 * Solution by mabernardo
 * https://github.com/mabernardo
 * https://www.hackerrank.com/mabernardo
 *
 */
 package main
 import (
 	"bufio"
 	"fmt"
 	"os"
 	"strconv"
 )

 func main() {
 	scanner := 	bufio.NewScanner(os.Stdin)
 	scanner.Split(bufio.ScanWords)

 	tests, _ := ScanInt(scanner)

 	for ; tests > 0; tests-- {
 		students, _ := ScanInt(scanner)
 		threshold, _ := ScanInt(scanner)

 		arrivals := make([]int, students)
 		for i := 0; i < students; i++ {
 			a, _ := ScanInt(scanner)
 			arrivals[i] = a
 		}

 		if Cancelled(arrivals, threshold) {
 			fmt.Println("YES")
 		} else {
 			fmt.Println("NO")
 		}
 	}
 }

func Cancelled(arrivals []int, threshold int) (bool) {
	ontime := 0
	for i := range arrivals {
		if arrivals[i] <= 0 {
			ontime++
		}
	}
	return ontime < threshold
}

func ScanInt(scanner *bufio.Scanner) (i int, err error) {
	scanner.Scan()
	i, err = strconv.Atoi(scanner.Text())
	return
}
