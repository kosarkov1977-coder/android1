package com.example.vulkangeometry

import android.os.Bundle
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

    external fun getGeometryDescription(): String

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        System.loadLibrary("vulkangeometry")

        val statusText = findViewById<TextView>(R.id.statusText)
        statusText.text = buildString {
            appendLine("Vulkan scene configured.")
            appendLine("Complex figure: stellated dodecahedron approximation.")
            append(getGeometryDescription())
        }
    }
}
