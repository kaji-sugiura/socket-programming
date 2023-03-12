# socket-programming

TCP, UDP, HTTP でのソケット通信を C 言語で実装してみました。

それぞれ以下のコマンドで実行することができます。

### TCP

サーバ実行

```
cd tcp
gcc server.c -o server
```

クライアント実行

```
cd tcp
gcc client.c -o client
```

### UDP

サーバ実行

```
cd udp
gcc server.c -o server
```

クライアント実行

```
cd udp
gcc client.c -o client
```

### HTTP

サーバ実行

```
cd http
gcc http.c -o httpd
```

ブラウザから以下を実行

```
http://localhost:9999(プログラムで設定したポート番号)
```
