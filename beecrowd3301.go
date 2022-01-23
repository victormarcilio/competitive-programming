package main

import (
	"fmt"
	"sort"
)

type Duck struct {
	name string
	age  int
}

type duckList []Duck

func (d duckList) Len() int {
	return len(d)
}

func (d duckList) Less(i, j int) bool {
	return d[i].age < d[j].age
}

func (d duckList) Swap(i, j int) {
	d[i], d[j] = d[j], d[i]
}

func main() {
	ducks := []Duck{Duck{name: "huguinho"}, {name: "zezinho"}, {name: "luisinho"}}
	fmt.Scanf("%d %d %d", &ducks[0].age, &ducks[1].age, &ducks[2].age)
	sort.Sort(duckList(ducks))
	fmt.Println(ducks[1].name)
}
