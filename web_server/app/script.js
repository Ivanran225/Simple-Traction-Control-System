function updateSliderPWM(element) {
    let sliderValue = document.getElementById("pwmSlider").value;
    let ip = document.getElementById("ipAddress").value;
    let errorMsg = document.getElementById("errorMsg");
    document.getElementById("textSliderValue").innerHTML = sliderValue;

    if (ip.match(/^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$/)) {
        var xhr = new XMLHttpRequest();
        xhr.open("GET", `http://${ip}/slider?value=${sliderValue}`, true);
        xhr.send();
        errorMsg.innerHTML = "";
    } else {
        errorMsg.innerHTML = "Invalid IP address";
    }
}
