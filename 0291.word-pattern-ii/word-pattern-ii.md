<p>Given a <code>pattern</code> and a string <code>str</code>, find if <code>str</code> follows the same pattern.</p>

<p>Here <b>follow</b> means a full match, such that there is a bijection between a letter in <code>pattern</code> and a <b>non-empty</b> substring in <code>str</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input: </strong>pattern = <code>&quot;abab&quot;</code>, str = <code>&quot;redblueredblue&quot;</code>
<strong>Output:</strong> true</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input: </strong>pattern = pattern = <code>&quot;aaaa&quot;</code>, str = <code>&quot;asdasdasdasd&quot;</code>
<strong>Output:</strong> true</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> pattern = <code>&quot;aabb&quot;</code>, str = <code>&quot;xyzabcxzyabc&quot;</code>
<strong>Output:</strong> false
</pre>

<p><b>Notes:</b><br />
You may assume both <code>pattern</code> and <code>str</code> contains only lowercase letters.</p>
