<script>
 () {
        return /iPhone|iPad|iPod|Android|webOS|BlackBerry|Windows Phone/i.test(navigator.userAgent);
    }

    // Mostra ou esconde o botão com base no dispositivo
    window.onload = function() {
        var button = document.getElementById("mobileButton");
        if (!isMobile()) {
            button.style.display = "none";
        }
    };
</script>
