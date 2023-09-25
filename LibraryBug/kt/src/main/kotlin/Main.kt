import java.util.UUID
import kotlin.random.Random
import kotlin.system.measureNanoTime
import kotlin.system.measureTimeMillis

fun main(args: Array<String>) {
    val input = (1000000L downTo 0L).map{
        it.toString().map {
            (it.code - '0'.code + 'A'.code).toChar()
        }.joinToString("") + it.toString()+ UUID.randomUUID().toString().filter { !it.isDigit() }
    }.sortRandom()
//    input.forEach{
//        println(it)
//    }
    var str = input
    val nanos = measureTimeMillis {
        str = str.sortByIndexesAndRemove()
    }
//    str.forEach{
//        println(it)
//    }
    println()
    println("Time $nanos")
}

fun String.getIndex(): Int = filter { it.isDigit() }.toInt()
fun List<String>.sortByIndexesAndRemove(): List<String> =
    sortedBy { it.getIndex() }.map { it.filter { !it.isDigit() } }
fun List<String>.sortRandom(): List<String> =
    sortedByDescending { Random.nextInt() }