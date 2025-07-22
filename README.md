Com o avanço dos processadores, que contam com um número cada vez maior de núcleos e, consequentemente, mais threads, torna-se essencial aproveitar essa tecnologia de forma eficiente.
No entanto, é preciso ter cautela ⚠️ ao lidar com threads, pois seu uso incorreto pode gerar problemas complexos, como condições de corrida e deadlocks.

🔁 Condições de corrida: quando mais de uma thread acessa uma região crítica, podendo ocasionar inconsistência de dados ou dados incorretos.

🔒Deadlocks: ocorrem quando uma thread detém um recurso e aguarda por outro recurso que está sendo mantido por uma segunda thread, enquanto esta segunda thread também aguarda um recurso que a primeira thread possui. Ambas aguardam por um recurso que, na situação atual, nunca será liberado.🔄

✅ Podemos usar mutexes para bloquear uma região crítica, permitindo apenas o acesso de uma thread por vez.
✅ Também o uso de semáforos pode ajudar a resolver problemas com multithread.

Nesse exemplo abaixo, temos um algoritmo para demonstrar duas funções: uma usando mutex e a outra não. Ambas incrementam até 100.000. Foram criadas 2 threads para cada função.

O resultado com mutex foi 200.000, o esperado, pois o acesso ao contador foi controlado, evitando erros. Sem mutex, o valor ficou em 117.727, menor que o esperado, porque as threads acessaram o contador ao mesmo tempo, causando perda de incrementos por condição de corrida.

❓Por que isso ocorreu?

Ambas as funções possuem uma região crítica, sendo o contador. Na função run_mtx(), foi usada uma "trava" para impedir o acesso das duas threads simultaneamente e evitar essa inconsistência.
Funciona da seguinte forma: assim que uma thread entra nessa região, ela é travada, e só será destravada quando a thread atual sair, o que ocorre apenas após o incremento.

Já na segunda função run(), não há essa proteção, permitindo que ambas as threads leiam o mesmo valor e não realizem o incremento correto do contador. 


<p align="center">
  <img src="https://github.com/user-attachments/assets/341e2954-01ae-489b-aeb8-279975fcd899" width="554" height="443" alt="mutex"/>
</p>

