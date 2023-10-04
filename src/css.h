const char* pag1 = R"html(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LED Control</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            height: 100vh;
            margin: 0;
            background-color: #f0f0f0;
            color: #333;
        }

        .tabs {
            display: flex;
            justify-content: center;
            margin-top: 30px;
        }

        .tab-button {
            padding: 10px 20px;
            margin: 0 5px;
            border: none;
            background-color: #ccc;
            cursor: pointer;
            transition: background-color 0.3s;
        }

        .tab-button.active, .tab-button:hover {
            background-color: #4CAF50;
            color: #fff;
        }

        .tab-content {
            display: none;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }

        .tab-content.active {
            display: flex;
        }

        .container {
            display: flex;
            flex-direction: column;
            align-items: center;
            border: 2px solid #ccc;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
            background-color: #fff;
        }

        .led {
            width: 50px;
            height: 50px;
            border-radius: 50%;
            background-color: grey;
            margin-bottom: 20px;
            box-shadow: 0 0 5px rgba(0, 0, 0, 0.5);
        }

        .btn-toggle {
            position: relative;
            width: 90px;
            height: 40px;
            border-radius: 100px;
            cursor: pointer;
            background-color: #f5f5f5;
            box-shadow: 0 0 5px rgba(0, 0, 0, 0.2);
            transition: background-color 0.3s ease;
            overflow: hidden;
        }

        .btn-toggle:before {
            content: "OFF";
            position: absolute;
            top: 50%;
            left: 10px;
            transform: translateY(-50%);
            color: #fff;
            font-size: 14px;
            font-weight: bold;
            line-height: 1;
            padding: 5px 8px;
            background-color: #f44336;
            border-radius: 100px;
            transition: transform 0.3s ease;
        }

        .btn-toggle.active {
            background-color: #4CAF50;
        }

        .btn-toggle.active:before {
            content: "ON";
            left: auto;
            right: 10px;
            background-color: #2196F3;
        }

        .description {
            text-align: center;
            margin: 20px 0;
        }

        .pot-value {
            font-size: 30px;
            font-weight: bold;
            color: #4CAF50;
            margin-top: 20px;
        }

        .checkbox {
            opacity: 0;
            position: absolute;
            width: 0;
            height: 0;
            margin: 0;
            padding: 0;
            overflow: hidden;
        }
    </style>
</head>

<body>
    <div class="tabs">
        <button class="tab-button active" onclick="showTab('led-control')">LED Control</button>
        <button class="tab-button" onclick="showTab('pot-meter')">Potentiometer</button>
    </div>

    <div id="led-control" class="tab-content active">
        <div class="container">
            <h1>LED Control</h1>
            <div class="led" id="led"></div>
            <div class="btn-toggle" id="btn-switch">
                <input type="checkbox" class="checkbox">
                <div class="on"></div>
                <div class="off"></div>
            </div>
            <div class="led" id="led2"></div>
            <div class="btn-toggle" id="btn-switch2">
                <input type="checkbox" class="checkbox">
                <div class="on"></div>
                <div class="off"></div>
            </div>
            <div class="description">
                <p>Pressione o botão para acender e apagar o LED.</p>
                <br>O LED 1 ficou aceso por: <span class="counter" id="counter">0 segundos</span>
                <br>O LED 2 ficou aceso por: <span class="counter" id="counter2">0 segundos</span>
            </div>
        </div>
    </div>

    <div id="pot-meter" class="tab-content">
        <div class="container">
            <h1>Value of Potentiometer</h1>
            <div class="pot-value" id="pot-value">0</div>
        </div>
    </div>

    <script>
        function showTab(id) {
            var contents = document.querySelectorAll('.tab-content');
            for (var content of contents) {
                content.classList.remove('active');
            }
            document.getElementById(id).classList.add('active');

            var buttons = document.querySelectorAll('.tab-button');
            for (var button of buttons) {
                button.classList.remove('active');
            }
            if (id == 'led-control') {
                buttons[0].classList.add('active');
            } else {
                buttons[1].classList.add('active');
            }
        }
    </script>

    <!-- The rest of your JavaScript remains unchanged -->
</body>

</html>
)html";
