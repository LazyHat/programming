import kotlinx.coroutines.*
import java.util.LinkedList
import java.util.Queue
import java.util.Stack
import javax.swing.DefaultFocusManager

fun main(args: Array<String>) = runBlocking {
    println("hello")
    val ce: CommandExecutor = CommandExecutorImpl(RequestBlocker())
    ce.requestAsync("1") { println("1. url = 1, result: $it") }
    ce.requestAsync("2") { println("2. url = 2, result: $it") }
    ce.requestAsync("1") { println("3. url = 1, result: $it") }
    ce.requestAsync("3") { println("4. url = 3, result: $it") }
    ce.requestAsync("1") { println("5. url = 1, result: $it") }
    delay(3000)
}

interface CommandExecutor {
    fun requestAsync(url: String, onResponse: (String) -> Unit)
}

class CommandExecutorImpl(
    val requestBlocker: RequestBlocker
) : CommandExecutor {
    override fun requestAsync(url: String, onResponse: (String) -> Unit) {
        CoroutineScope(Dispatchers.Unconfined).launch {
            onResponse(requestBlocker.request(url))
        }
    }
}

class RequestBlocker {
    val responses: MutableMap<String, Deferred<String>> = emptyMap<String, Deferred<String>>().toMutableMap()

    suspend fun request(url: String): String {
        println("request url: $url")
        val scope = CoroutineScope(Dispatchers.Unconfined)
        return responses[url].let {
            if (it == null) {
                println("url: $url does not exists in responses")
                scope.async {
                    Device.requestSync(url)
                }.also {
                    responses[url] = it
                    it.invokeOnCompletion {
                        responses.remove(url)
                    }
                }
            } else {
                println("url: $url exists in responses")
                it
            }.await()
        }
    }
}

object Device {
    suspend fun requestSync(url: String): String {
        println("sync request url $url executed")
        delay(1000)
        return "response from url $url"
    }
}