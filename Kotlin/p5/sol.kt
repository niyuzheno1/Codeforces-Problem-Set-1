import java.util.*

fun max(a : Int, b: Int) : Int{
    if(a > b){
        return a;
    }
    return b;
}
 
fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    
        var n = sc.nextInt();
        var k = sc.nextInt();
        var x = sc.nextInt();
        var aa = ArrayList<Pair<Int, Int>>();
        var a = IntArray(n);
        for (i in 1..n){
            var x = sc.nextInt();
            aa.add(Pair(x,i-1));
            a[i-1] = x;
        }
        val complexComparator = compareBy<Pair<Int, Int?>>(  {it.first}, {it.second});
        var b = aa.sortedWith(complexComparator);
        for (i in 1..k){
            var pos = b.size - i;
            a[b[pos].second] = -1;
        }
        var maxsum = 0;
        var i = 0;
        while(i < a.size){
            var sum = 0;
            var j = 0;
            while(j < x && i < a.size){
                if(a[i] > 0){
                    sum += a[i];
                    ++j; ++i;
                }else{
                    ++i;
                }
            }
            maxsum = max(maxsum,sum);
        }
        println("$maxsum");
    
}