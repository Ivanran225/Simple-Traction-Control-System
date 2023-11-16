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

document.addEventListener('DOMContentLoaded', function () {
    // Add animation class dynamically after DOM is loaded
    document.querySelectorAll('.button').forEach(function (button) {
        button.classList.add('animate-lightning');
    });
});