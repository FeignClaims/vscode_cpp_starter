window.addEventListener("load", (event) => {
  if (window.localStorage) {
    if (!localStorage.getItem("firstLoad")) {
      localStorage["firstLoad"] = true;
      setTimeout(() => window.location.reload(), 3000);
    } else localStorage.removeItem("firstLoad");
  }
});
