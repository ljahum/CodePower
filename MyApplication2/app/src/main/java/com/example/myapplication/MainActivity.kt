package com.example.myapplication

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import com.example.myapplication.ui.theme.MyApplicationTheme

import android.util.Base64
import java.nio.charset.Charset
import javax.crypto.Cipher
import javax.crypto.EncryptedPrivateKeyInfo
import javax.crypto.spec.IvParameterSpec
import javax.crypto.spec.SecretKeySpec
import kotlin.math.log


/** 加密key  */
private var PASSWORD_ENC_SECRET = "xxxxxxx-20202020"
/** 加密算法 */
private const val KEY_ALGORITHM = "AES"
/** 字符编码 */
private val CHARSET = Charset.forName("UTF-8")
/** 加解密算法/工作模式/填充方式 */
private const val CIPHER_ALGORITHM = "AES/CBC/PKCS7Padding"


fun String.encrypt(): String {
    val cipher = Cipher.getInstance(CIPHER_ALGORITHM)
    val byteArray = PASSWORD_ENC_SECRET.toByteArray(CHARSET)
    val keySpec = SecretKeySpec(byteArray, KEY_ALGORITHM)
    cipher.init(Cipher.ENCRYPT_MODE, keySpec, IvParameterSpec(byteArray))
    val encrypted = cipher.doFinal(this.toByteArray(CHARSET))
    return Base64.encodeToString(encrypted, Base64.NO_WRAP)
}

/**
 * 对字符串解密
 * @param data  已被加密的字符串
 * @return  解密得到的字符串
 */
fun String.decrypt(): String {
    val encrypted = Base64.decode(this.toByteArray(CHARSET), Base64.NO_WRAP)
    val cipher = Cipher.getInstance(CIPHER_ALGORITHM)
    val byteArray = PASSWORD_ENC_SECRET.toByteArray(CHARSET)
    val keySpec = SecretKeySpec(byteArray, KEY_ALGORITHM)
    cipher.init(Cipher.DECRYPT_MODE, keySpec, IvParameterSpec(byteArray))
    val original = cipher.doFinal(encrypted)
    return String(original, CHARSET)
}
fun add(x: Int , y: Int): String {
    val tmp:Int = x+y;
//    log(tmp);
    return tmp.toString();
}



class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            MyApplicationTheme {
                // A surface container using the 'background' color from the theme

                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    val tmp:String =  ("Android\n"+add(123,456))
                    Greeting(Base64.encodeToString(tmp.toByteArray(), Base64.NO_WRAP))
                    Text(
                        text = "\n234234234234",

                    )
                }
            }
        }
    }
}


@Composable
fun Greeting(name: String, modifier: Modifier = Modifier) {
    Text(
        text = "Hello $name!\n",
//        modifier = modifier
    )
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    MyApplicationTheme {
        Greeting("Android")
    }
}