def bubblesort(lst : Array[Int]) : Array[Int] =
{
	val list : Array[Int] = new Array[Int](lst.length)
	Array.copy(lst, 0, list, 0, lst.length)
	var swapped = false
	do
	{
		swapped = false
		for (i <- 0 to (list.length - 2))
		{
			if (list(i) > list(i+1))
			{
				swapWithNext(i, list)
				swapped = true
			}
		}
	} while (swapped)

	return list
}

def swapWithNext(i : Int, list:Array[Int]) : Unit =
{
	val temp = list(i)
	list(i) = list(i+1)
	list(i+1) = temp
}


def binSearchIter(list: Array[Int], target: Int): Int = {
	var left = 0
	var right = list.length-1
	while (left<=right) {
		val mid = left + (right-left)/2
		if (list(mid)==target)
			return mid
		else if (list(mid)>target)
			right = mid-1
		else
			left = mid+1
		}
	  -1
}

def binSearchRecur(list: Array[Int], target: Int)
	(start: Int=0, end: Int=list.length-1): Int = {
		if (start>end) return -1
		val mid = start + (end-start+1)/2
		if (list(mid)==target)
			return mid
		else if (list(mid)>target)
			return binSearchRecur(list, target)(start, mid-1)
		else
			return binSearchRecur(list, target)(mid+1, end)
}

println("Enter numbers seperated by space:")
val s = readLine
val list: Array[Int] = s.split(" ").map(_.toInt)
val lst = bubblesort(list)
lst.foreach(println)
println("Enter value to be searched:")
val v = readInt
var index = -1
println("1) Iterative search 2) Recursive search:")
val chc = readInt
if(chc == 1)
{
	index = binSearchIter(lst, v)
}
else if(chc == 2)
{
	index = binSearchRecur(lst, v)(0, lst.length - 1)
}
println("Index:")
println(index)
