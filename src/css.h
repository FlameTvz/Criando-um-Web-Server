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
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
      margin: 0;
      background-color: #f0f0f0;
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
      margin-bottom: 20px;
    }

    .counter {
      font-size: 18px;
      color: #555;
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
      <p>Pressione o botão para acender e apagar o LED.</p><br>O LED 1 ficou aceso por: <span class="counter" id="counter">0 segundos</span><br>
      O LED 2 ficou aceso por: <span class="counter" id="counter2">0 segundos</span>
    </div>
  </div>

  <script>
    var ledStatus1 = {ledStatus1} == 1 ? true : false;
    var ledStatus2 = {ledStatus2} == 1 ? true : false;
    var ledElement = document.getElementById("led");
    var btnToggle = document.getElementById("btn-switch");
    var counterElement = document.getElementById("counter");
    var intervalId;
    var secondsCounter = 0;

    var ledElement2 = document.getElementById("led2");
    var btnToggle2 = document.getElementById("btn-switch2");
    var counterElement2 = document.getElementById("counter2");
    var intervalId2;
    var secondsCounter2 = 0;

    function toggleLED(ledElement, btnToggle, counterElement, intervalId, secondsCounter) {
      if (btnToggle.classList.contains("active")) {
        ledElement.style.backgroundColor = "grey";
        clearInterval(intervalId);
      } else {
        ledElement.style.backgroundColor = "red";
        intervalId = setInterval(function() {
          secondsCounter++;
          counterElement.textContent = secondsCounter + " segundos";
        }, 1000);
      }

      btnToggle.classList.toggle("active");

      var id = ledElement.id === "led" ? 1 : 2;

      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // Resposta do servidor (opcional)
        }
      };

      xhttp.open('POST', '/toggle-led?id=' + id, true);
      xhttp.send();
    }

    function toggleLED2() {
      toggleLED(ledElement2, btnToggle2, counterElement2, intervalId2);
    }

    btnToggle.addEventListener("click", function() {
      toggleLED(ledElement, btnToggle, counterElement, intervalId);
    });

    btnToggle2.addEventListener("click", toggleLED2);
    
    function setLEDState(ledElement, btnToggle, counterElement, intervalId, secondsCounter, state) {
  if (state) {
    ledElement.style.backgroundColor = "red";
    intervalId = setInterval(function() {
      secondsCounter++;
      counterElement.textContent = secondsCounter + " segundos";
    }, 1000);
    btnToggle.classList.add("active");
  } else {
    ledElement.style.backgroundColor = "grey";
    clearInterval(intervalId);
    btnToggle.classList.remove("active");
  }
}
    window.onload = function() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            var ledStates = JSON.parse(this.responseText);
            setLEDState(ledElement, btnToggle, counterElement, intervalId, secondsCounter, ledStates.led1);
            setLEDState(ledElement2, btnToggle2, counterElement2, intervalId2, secondsCounter2, ledStates.led2);
        }
    };
    xhttp.open('GET', '/get-led-state', true);
    xhttp.send();
}
  </script>
</body>
</html>)html";
