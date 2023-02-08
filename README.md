### Закрепляемые знания:
Работа с сигналами и слотами. Работа с qml для создания простого визуального интерфейса. MouseArea. Условия. Таймер.

### Задача:
Реализовать простую игру для кошек. По экрану перемещается объект. При нажатии на него, он должен появляться в новом месте.  
<image src="/1. image/1.png" alt="1">

### Решение:
Реализовать движение объекта по таймеру и обработку столкновений с границами экрана. При нажатии на объекте, он должен появляться в новом месте экрана.

Создайте приложения под две версии устройств: android и desktop. Переключитесь на версию desktop.  
<image src="/1. image/2.png" alt="2">
 
В первую очередь создайте мышь (круг), которая в дальнейшем будет осуществлять движение. Для создания круга воспользуйтесь прямоугольником, которому укажите закругление. Чтобы получить круг, необходимо ширину (высоту) поделить на 2 (это значение будет являться радиусом).  
<image src="/1. image/3.png" alt="3">  
В первую очередь реализуйте движение круга при нажатии на него. 
Создайте новый С++ файл. Назовите его Mouse. Настройки класса:  
<image src="/1. image/4.png" alt="4">  
Перейдите к заголовочному файлу. 
Создайте свойства для координат объекта:  
<image src="/1. image/5.png" alt="5">  
Объявите для них геттеры:  
<image src="/1. image/6.png" alt="6">  
Для уведомления qml об изменениях объявите сигнал:  
<image src="/1. image/7.png" alt="7">  
Укажите переменные для координат.  
<image src="/1. image/8.png" alt="8">  
Далее для изменения позиции создайте слот:  
<image src="/1. image/9.png" alt="9">  
Создайте реализацию геттеров и слота в классе mouse.cpp:  
<image src="/1. image/10.png" alt="10">  
В геттерах верните соответствующее значение:    
<image src="/1. image/11.png" alt="11">  

Перейдите к методу changePosition(). Здесь необходимо изменять положение мыши на случайное место на экране. Для этого воспользуйтесь функцией rand(), которая возвращает псевдослучайное целое число в диапазоне от 0 до максимального значения. Для генерации значений в определенном промежутке (по размерам окна) нужно поделить случайное число на максимальное значение (для координаты “х” это ширина окна, для координаты “у” это высота окна)..
Присвойте “x” случайное значение:  
<image src="/1. image/12.png" alt="12">  
Необходимо случайное число ограничить шириной экрана. Она равна 640. Возьмите остаток от деления случайного числа на данное значение:  
<image src="/1. image/13.png" alt="13">  
Высота окна 480. По аналогии сформируйте случайно значение:  
<image src="/1. image/14.png" alt="14">  
После изменения координат вызовите сигнал, что зафиксировать изменения:  
<image src="/1. image/15.png" alt="15">  
Перейдите к файлу main.cpp. Зарегистрируйте новый тип, чтобы обратиться в qml к созданному методу.  
<image src="/1. image/16.png" alt="16">  

Вернитесь в qml файл. Для проверки работы описанной логики подключите зарегистрированный тип и создайте новый объект:  
<image src="/1. image/17.png" alt="17">  
Для изменения положения объекта необходимо задать ему координаты. Координаты должны быть получены из ранее описанного класса:  
<image src="/1. image/18.png" alt="18">  
Изменение координат происходит при нажатии на сам объект мыши. Вызовите MouseArea для прослушивания действия:  
<image src="/1. image/19.png" alt="19">  
В обработке нажатия вызовите метод изменения позиции:  
<image src="/1. image/20.png" alt="20">  
Запустите приложение. При нажатии на мышь она должна отображаться в новом месте:  
<image src="/1. image/21.png" alt="21">  
Мышь выходит за пределы экрана. Чтобы этого не происходило вычтите из ширины и высоты (при формировании случайного значения) размеры  самого объекта:  
<image src="/1. image/22.png" alt="22">  
При запуске, объект не должен уходить за пределы экрана.
Добавьте счет количества пойманных мышек. Для этого в заголовочном файле объявите новое свойство:  
<image src="/1. image/23.png" alt="23">  
Создайте для него геттер и объявите переменную, которую будете возвращать:  
<image src="/1. image/24.png" alt="24">  
Объявите сигнал, для оповещения об изменениях:  
<image src="/1. image/25.png" alt="25">  
Для увеличения счета можно воспользоваться уже существующим слотом, так как смена позиции будет происходить только при нажатии на объект. Перейдите к реализации метода изменения положения мыши. В нем произведите увеличение значения:  
<image src="/1. image/26.png" alt="26">  
Вызовите сигнал для оповещения об изменениях:  
<image src="/1. image/27.png" alt="27">  
Добавьте реализацию геттера для получения значения:  
<image src="/1. image/28.png" alt="28">  
Вернитесь в qml файл. Создайте в нем текстовое поле и выведите в нем счет:  
<image src="/1. image/29.png" alt="29">  
Запустите приложение. Счет должен увеличиваться при нажатии на мышь:  
<image src="/1. image/30.png" alt="30">  

### Добавление таймера. 
Перейдите к заголовочному файлу. Объявите новый слот, для реализации движения мыши по таймеру. Объявите его:  
<image src="/1. image/31.png" alt="31">  
Создайте его реализацию в mouse.cpp. В методе необходимо обработать ограничения движения мыши (чтобы она не выходила за пределы экрана) и прописать направление движения.  
Пропишите движение объекта исходя из случайного значения. Случайное значение должно формироваться от -5 до 4. Сохраните значение в отдельную переменную:  
<image src="/1. image/32.png" alt="32">  

Это значение будет определять шаг и направление движения. Если оба значения 0, необходимо сформировать новое значение:  
<image src="/1. image/33.png" alt="33">  
Перед присваиванием значения координатам необходимо проверить, не выйдет ли мышь за пределы экрана. Для этого воспользуйтесь условием. Реализуйте проверку того, что мышь не выходит за границу вправо.
Верхний левый угол соответствует координате 0. Ширина мыши 100. Для того чтобы она полностью исчезла за пределами экрана следующий шаг должен быть меньше -100. Условие от обратного будет выглядеть как: “Следующий шаг должен быть больше -100”. Для вычисления следующего шага к текущей координате прибавьте полученное случайное выражение:  
<image src="/1. image/34.png" alt="34">  

Пропишите ограничение справа. Для этого следующий шаг должен быть меньше ширины экрана:  
<image src="/1. image/35.png" alt="35">  
Далее ограничение по “у”. Для движения вверх следующий шаг должен быть больше -100 (высота объекта):  
<image src="/1. image/36.png" alt="36">  
Для движения вниз следующий шаг должен быть меньше 480:  
<image src="/1. image/37.png" alt="37">  
Только если условие верно, увеличьте значение переменной координаты на шаг:  
<image src="/1. image/38.png" alt="38">  
После изменения координаты необходимо оповестить об этом qml. Вызовите:  
<image src="/1. image/39.png" alt="39">  
Вернитесь к qml.
Для постоянного движения объекта необходимо создать таймер. Воспользуйтесь встроенным таймером qml.
Подключите новую библиотеку с контроллерами:  
<image src="/1. image/40.png" alt="40">  
Создайте объект таймер:  
<image src="/1. image/41.png" alt="41">  
Задайте значение интервалу, который будет указывать через сколько миллисекунд будет совершен следующий тик:  
<image src="/1. image/42.png" alt="42">  
Для того чтобы была не одна итерация, необходимо установить repeat в значение true (таймер не останавливался, пока не нажата кнопка “стоп”):  
<image src="/1. image/43.png" alt="43">  
Для описания действия, которое будет происходить в триггере после интервала, воспользуйтесь свойством onTriggered:  
<image src="/1. image/44.png" alt="44">  
Внутри вызовите ранее описанное движение:  
<image src="/1. image/45.png" alt="45">  
Таймер необходимо запустить. Создайте кнопку, которая будет запускать игру. Чтобы кнопка не перекрывала счет, создайте строку, в нее перенесите счет:  
<image src="/1. image/46.png" alt="46">  

При нажатии на кнопку запустите таймер:  
<image src="/1. image/47.png" alt="47">  
Запустите приложение. Мышь после нажатия на кнопку начнет двигаться, но ее шаги будут мелкими. Для изменения этого дополните метод move():  
<image src="/1. image/48.png" alt="48">  
srand - инициализация генератора случайных чисел. time - возвращает текущее время системы, можно передать 0 в качестве аргумента.

Сейчас объект мыши отображается поверх счета и кнопки запуска.  Измените начальное положение мыши. Для этого в заголовочном файле установите значение:  
<image src="/1. image/49.png" alt="49">  


Статус игры.
Даже без запуска таймера мышь будет реагировать на нажатие. Это можно изменить. Перейдите к заголовочному файлу и объявите новое свойство, которое будет определять, запущена ли игра на выполнение:  
<image src="/1. image/50.png" alt="50">  
Для изменения свойства воспользуйтесь сеттером (WRITE).
Создайте геттер для получения состояния:  
<image src="/1. image/51.png" alt="51">  

Объявите сигнал, который будет оповещать об изменении состояния:  
<image src="/1. image/52.png" alt="52">  

Для сеттера создайте новый слот, который будет принимать логическое выражение на вход:  
<image src="/1. image/53.png" alt="53">  

Создайте переменную. Игра еще не запущена, значит состояние по умолчанию false:  
<image src="/1. image/54.png" alt="54">  

Добавьте реализацию геттера в mouse.cpp. Укажите, что геттер возвращает значение:  
<image src="/1. image/55.png" alt="55">  

Добавьте в файл реализацию сеттера. Укажите изменение значения:  
<image src="/1. image/56.png" alt="56">  

Добавьте дополнительную проверку в метод changePosition(). Если значение state равна false, позиция объект не должна изменяться:  
<image src="/1. image/57.png" alt="57">  

При нажатии на кнопку вызовите сеттер, чтобы изменить значение статуса игры:  
<image src="/1. image/58.png" alt="58">  
Пока игра не началась, мышь не будет реагировать на нажатие.

### Остановка игры.
Можно реализовать остановку игры. Для этого добавьте еще одну кнопку:  
<image src="/1. image/59.png" alt="59">  
При нажатии на кнопку остановите таймер:  
<image src="/1. image/60.png" alt="60">  
И укажите, что игра остановлена (присвойте переменной значение false):  
<image src="/1. image/61.png" alt="61">  
Проверьте работу приложения:  
<image src="/1. image/62.png" alt="62">  
Задача:
Отредактируйте движение мыши, чтобы она всегда оставалась в пределах окна.

