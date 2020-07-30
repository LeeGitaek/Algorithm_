//
// Created by GiTaek Lee on 2020/07/31.
//

import Foundation

/* 삽입 정렬 사용  (삽입 정렬 이외에 좀 더 빠른 정렬 사용 가능 ) */
func insertionSort(alist:inout[Int]){
    for i in 1..<alist.count {
        let tmp = alist[i]
        var j = i-1
        while j >= 0 && alist[j] > tmp{
            alist[j+1] = alist[j]
            j = j-1
        }
        alist[j+1] = tmp
    }
}

/* 솔루션 함수 */
func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var someSubset:[Int] = []
    var result:[Int] = []
    for el in commands {
        let a:Int = el[0]-1
        let b:Int = el[1]-1
        for i in a..<b+1 {
            someSubset.append(array[i])
        }
        insertionSort(alist:&someSubset)
        result.append(someSubset[el[2]-1])
        someSubset = []
    }

    return result
}