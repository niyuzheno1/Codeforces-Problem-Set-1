import java.util.*
 
 
fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val t = sc.nextInt();
    for (jj in 1..t){
        var n = sc.nextInt();
        var aa = ArrayList<Pair<Int, Int>>();
        var b = IntArray(n);
        for (i in 1..n){
            var x = sc.nextInt();
            aa.add(Pair(x,i-1));
            b[i-1] = 0;
        }
        val complexComparator = compareBy<Pair<Int, Int?>>(  {it.first}, {it.second});
        var a = aa.sortedWith(complexComparator);
        
        var back = n-1;
        var i = 0;
        var used = 0;
        while(i < back){
            var cnt = used;
            while(i < back && cnt < a[i].first){
                var xx = a[back].second+1;
                print(xx); print(" ");
                b[a[back].second] = 1;
                --back;
                ++cnt;
            }
            b[a[i].second] = 1;
            print(a[i].second+1); print(" ");
            ++i;used=1;
        }
        i = b.size-1;
        while(i >= 0){
            if (b[i] == 0){
                print(i+1); print(" ");
            }
            --i;
        }
        println();
    }
}