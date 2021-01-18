import java.util.*
 
fun max(a : Long, b: Long) : Long{
    if (a > b){
        return a;
    }
    return b;
}
 
fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    var t = sc.nextInt();
    for (i in 1..t)
	{
		val n = sc.nextInt();
        var a = LongArray(n);
        for (j in 1..n){
            val x = sc.nextLong();
            a[j-1] = x;
        }
        a.sort();
        var ans : Long = 0;
        for (j in 1..n){
            ans = max(ans, a[j-1] *(n-j+1));
        }
        println("$ans");

	 }
}