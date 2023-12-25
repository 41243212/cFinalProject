# Wordle猜字遊戲
級別:112<br>
班級:資工一乙<br>
姓名:王稔中<br>
學號:41243212<br>
## 介紹
Wordle 是一款文字遊戲([https://www.nytimes.com/games/wordle/index.html 原始遊戲])，目的是找出一個五個字母單字，每次猜測會依照猜測的狀況分別顯示綠色(完全正確)、黃色(字母有出現，但字母位置不正確)、白色(字母沒出現)。

程式會讀取自訂的字典列表，從中隨機選擇單字作為謎題。並且可以在不揭露答案的情況下，記錄答題狀況，並將答題的情況顯示出來。

[Demo影片](https://www.youtube.com/watch?v=egJnifGDWL0)

## 功能條列說明

* 主選單
    * 開始遊戲
    * 讀取歷史紀錄
    * 清空歷史紀錄
    * 離開遊戲
* 遊戲部分
    * 從檔案裡隨機選擇單詞作為謎題
    * 玩家輸入5字單字
    * 檢測是否正確 並依結果印出不同背景顏色
    * 猜對或猜錯6次則結束遊戲
    * 結束後，使用者輸入名字，儲存遊戲結果到到檔案裡
* 讀取遊戲紀錄
    * 從檔案讀取遊戲紀錄
    * 輸出玩家名字及紀錄
* 清除紀錄
    * 清空儲存遊戲紀錄的檔案

## 程式結構圖

* main()主程式
    * 顯示選單(無限迴圈)
    * 依選擇呼叫子程式
    * 呼叫lineCount()計算字典檔行數，從檔案抽選其中一行的單字，作為引數呼叫startGame()遊戲主體函式，遊戲結束時接收結果並儲存到檔案
    * 呼叫showHistory()顯示記錄函式
    * 呼叫clearHistory()清除記錄函式
* startGame()遊戲主體
    * 讀取主程式傳過來的單字參數
    * 讓玩家猜6次或猜對即結束遊戲
    * 比對輸入和答案，正確顯示綠色，有出現但位置錯誤顯示黃色，錯誤顯示白色。
    * 回傳遊戲結果到主程式
* showHistory()顯示記錄
    * 讀取檔案
    * 印出玩家名字
    * 印出遊戲結果
* clearHistory()清除記錄
    * 開啟檔案並清除其內容
* lineCount()計算行數
    * 計算\n數量
    * 回傳數值


# 流程圖
![主程式](https://i.imgup.co/pi5xs.png)
![Wordle遊戲主體程式](https://i.imgup.co/piziY.jpg)

## 技術使用說明
* 第1章
    1. 流程圖
    2. 註解
* 第2章
    1. 載入標頭檔
    2. 宣告常數(int, char)、變數
    3. ASCII字元處理(換行、顏色)
    4. 設中斷點debug
* 第3章
    1. 讀取、輸出(scanf, printf)
    2. 字串的宣告、讀取、輸出
    3. scanf輸入字元的檢測
* 第4章
    1. 算術運算子
    2. 關係運算子
    3. 遞增遞減運算子
    4. if敘述
    5. while迴圈
    6. 自訂函式
* 第5章
    1. if-else敘述
    2. 巢狀if架構
    3. switch-case
    4. 亂數產生 rand
* 第6章
    1. for迴圈
    2. 巢狀迴圈
    3. 陣列(一維、二維)
    4. 無窮迴圈的跳離
* 第7章
    1. 自訂函式原形宣告
    2. 自訂函式引數傳遞及回傳值
    3. 變數的活動範圍
    4. 靜態變數 static
* 第8章
    1. 指標
    2. 函式傳指標(字串)
* 第9章
    1. 結構(struct)的宣告
    2. 結構陣列
    3. 結構指標變數
    4. enum列舉
    5. typedef型別名稱定義
* 第10章
    1. 檔案讀取
    2. 檔案寫入

## 心得
這次的專題讓我把結構、指標、檔案處理這些比較困難的單元實際操作了一遍，讓我有比較深的了解。<br>
在字元陣列組合成的字串的處理上，遇到了一些困難。會有一些意想不到的記憶體存取問題。<br>
在設計程式架構時，我嘗試讓結構清晰、模組化，主選單、遊戲部分和文件處理各自獨立，讓程式更易於理解和修改。<br>
在和玩家的互動上，也使用了選單來方便玩家選擇不同的功能，遊戲的部分用到了上課沒教的顯示顏色文字的功能，增進遊戲體驗。<br>
這次專題的開發是一項有挑戰性又有趣的體驗，讓我更深入地了解了C語言的運用，讓我把上課所教的複習了一遍，也學到了一些上課沒教的，讓我的程式技巧更加紮實。
## 開發時間
2023/11/21, 1hr, 繪製遊戲主體流程圖、撰寫程式說明

2023/12/14, 5hr, 遊戲本體程式撰寫、建立Github專案

2023/12/21, 5hr, 增加主選單、儲存/讀取歷史紀錄的功能、wiki功能條列說明撰寫

2023/12/25, 3hr, 流程圖繪製、程式結構、心得撰寫