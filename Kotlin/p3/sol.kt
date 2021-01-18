import java.util.*
 
fun max(a : Int, b: Int) : Int{
    if (a > b){
        return a;
    }
    return b;
}
fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val t = sc.nextInt();
    for (i in 1..t){
        var n = sc.nextInt();
        var k = sc.nextInt();
        var a = IntArray(n);
        for (j in 1..n){
            var x = sc.nextInt();
            a[j-1] = x;
        }
        var ans = 0;
        for(jp in 1..n){
            var j = jp-1;
            var x = n-j;
            var xk = x/k;
            var l = 0;
            var u = 0;
            while(l < xk && j+l < n){
                u += a[j+l];
                ++l;
            }
            ans = max(ans,u);
        }
        println("$ans");
    }
}