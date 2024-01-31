window.addEventListener("DOMContentLoaded", (event) => {
  if (window.localStorage) {
    if (!localStorage.getItem("firstLoad")) {
      localStorage["firstLoad"] = true;
      setTimeout(() => window.location.reload(), 1000);
    } else localStorage.removeItem("firstLoad");
  }
});
