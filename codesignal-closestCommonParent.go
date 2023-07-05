//https://app.codesignal.com/company-challenges/datto/qTNybKyWB9Nj72x8h
func solution(files []string, parents []string, file1 string, file2 string) string {
    parents1 := map[string]bool{file1:true}
    
    fillParents := func(parentsMap map[string]bool, current string) {
        for current != "-1" {
            for i, file := range files {
                if file == current {
                    parentsMap[parents[i]] = true
                    current = parents[i]
                    break
                }
            }
        }
    }    
    
    fillParents(parents1, file1)
    
    for !parents1[file2] {
        for i, file := range files {
            if file == file2 {                
                file2 = parents[i]
                break
            }
        }
    }
    return file2
}
