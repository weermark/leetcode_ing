# vim常用指令整理

>所有的編輯指令，都必須在英文輸入法下才能作用。

>建議安裝英文輸入法 (`<win>` + `<space>`切換輸入法)，並將`<caps lock>`鍵改成`<ctrl>` (window提供power toys軟體供改鍵)。

>更多改鍵想法可參考HHKB鍵盤配置。

<br/>

## **1.編輯模式 (insert-mode)(線光標)**

<br/>

### *切換*
指令|用途
---|---
`<ctrl>` [|切換normal
`<esc>`|切換normal

<br/>


## **2.普通模式 (normal-mode)(格光標)**

<br/>

### *切換*
指令|用途
---|---
v|切換visual，單格選取
V|切換visual，單列選取
`<ctrl>` v|切換visual，單行選取
i|切換insert，光標移動到字元前
a|切換insert，光標移動到字元後
I|切換insert，光標移動到列首
A|切換insert，光標移動到列尾
o|切換insert，下一列新增一列
:|切換command，後續可加指令
/|切換command，向下搜尋
?|切換command，向上搜尋

<br/>

### *光標移動* (num加指令表示做num次指令)
指令|用途
---|---
h|光標左移
j|光標下移
k|光標上移
l|光標右移
w|光標移至下個單字的頭
e|光標移至下個單字的尾
b|光標移至上個單字的頭
0|光標移至當列頭
$|光標移至當列尾
H|光標移至畫面頂
M|光標移至畫面中
L|光標移至畫面底


<br/>

### *畫面移動*
指令|用途
---|---
`<ctrl>` e|畫面向下移動一格
`<ctrl>` y|畫面向上移動一格
`<ctrl>` d|畫面向下移動半頁
`<ctrl>` u|畫面向上移動半頁


<br/>

### *編輯* (num加指令表示做num次指令)

指令|用途
---|---
r|替換光標字元
x|刪除光標文字
dd|刪除當列
dw|刪除一個單字 (delete word)
di{|刪除{}內的內容 (delete inside { })
da{|刪除{}內的內容，包含{}符號 (delete all { })
yy|複製當列
yw|複製光標所在單字
<<<<<<< HEAD
p|貼上
10p|貼上10次
"+p|vim環境外複製的文字，可用此指令貼上
=======
p|在下一列新增一列，並貼上
10p|貼10次
>>>>>>> ecaed9df7618ec45de5e733b77265228efa820f3
J|當列與下一列合併
u|復原
`<ctrl>` r|重複
.|重複(同上)
`>>`|縮排(同tab)
`<<`|取消縮排(往前一tab))

<br/>


## **3.命令模式 (command-mode)(底線光標)**

<br/>

指令|用途
---|---
/word|向光標下方搜尋word (加n繼續往下搜尋)
?word|向光標上方搜尋word
:w|儲存
:q|離開
:num|跳到第num列
:%s/word1/word2/gc|全部word1替換成word2，參數g(global)整列全部換(非只換一列第一個)，c(comfirm)取代前確認。參數可不加
:num1,num2`s`/word1/word2/gc|num1到num2列的word1替換成word2，參數說明同上

<br/>


## **4.可視模式 (visual-mode)(不閃爍格光標)**

<br/>

用於選取
<<<<<<< HEAD

指令|用途
---|---
`<ctrl>` v選取後按`I`|可多行插入輸入文字
=======
>>>>>>> ecaed9df7618ec45de5e733b77265228efa820f3
