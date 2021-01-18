import java.util.*
 
 
fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    var t = sc.nextInt();
    sc.nextLine();
    for (j in 1..t){
        var ss:String = sc.nextLine();
        var s = ss.toCharArray();
        var ans: Int = 0 ;
        var cnt: Int = 0;
        for (i in 1..s.size){
            if(s[i-1] == 'v'){
                ++cnt;
            }else{
                ++ans;
                ans += cnt/2;
                cnt = 0;
            }
        }
        ans += cnt/2;
        
        println("$ans");
    }
}