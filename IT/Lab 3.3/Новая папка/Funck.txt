
function ShowOp(arg, value, index) {
    var option = new Option(value, index);
    switch (arg) {
        case 0:
            {
                document.getElementById("faculty").options[index] = option;
            }
            break;
        case 1:
            {
                document.forms[0].course.options[index] = option;
            }
            break;
        case 2:
            {
                document.forms[0].group.options[index] = option;
            }
            break;
        case 3:
            {
                document.forms[0].student.options[index] = option;
            }
            break;
    }
}

function LoadDoc() {

    var xmldoc = new ActiveXObject("Microsoft.XMLDOM");
    xmldoc.async = false;
    xmldoc.load("data.xml");

    faculty = xmldoc.getElementsByTagName("faculty");
    document.getElementById("faculty").length = 0;
    for (var i = 0; i < faculty.length; i++){     
        ShowOp(0, faculty.item(i).getAttribute("name"), i);
    }

    course = faculty.item(0).getElementsByTagName("course");
    document.forms[0].course.length = 0;
    for (var i = 0; i < course.length; i++)
        ShowOp(1, course.item(i).getAttribute("num"), i);

    group = course.item(0).getElementsByTagName("group");
    document.forms[0].group.length = 0;
    for (var i = 0; i < group.length; i++)
        ShowOp(2, group.item(i).getAttribute("name"), i);

    student = group.item(0).getElementsByTagName("student");
    document.forms[0].student.length = 0;
    for (var i = 0; i < student.length; i++)
        ShowOp(3, student.item(i).getAttribute("name"), i);

    rating = student.item(0).getElementsByTagName("rating");
    for (var i = 0; i < rating.length; i++)
        eval("document.forms[0].pr" + (i + 1) + ".item(" + rating.item(i).text + ").checked = true");

}

function ch_sel(arg, value) {
    switch (arg) {
        case 0:
            {
                course = faculty.item(value).getElementsByTagName("course");
                document.forms[0].course.length = 0;
                for (var i = 0; i < course.length; i++)
                    ShowOp(1, course.item(i).getAttribute("num"), i);
                ch_sel(1, 0);
            }
            break;

        case 1:
            {
                group = course.item(document.forms[0].course.value).getElementsByTagName("group");
                document.forms[0].group.length = 0;
                for (var i = 0; i < group.length; i++)
                    ShowOp(2, group.item(i).getAttribute("name"), i);
                ch_sel(2, 0);
            }
            break;

        case 2:
            {
                student = group.item(document.forms[0].group.value).getElementsByTagName("student");
                document.forms[0].student.length = 0;
                for (var i = 0; i < student.length; i++)
                    ShowOp(3, student.item(i).getAttribute("name"), i);
            }
            break;

        case 3:
            {
                student = group.item(document.forms[0].group.value).getElementsByTagName("student");
                rating = student.item(value).getElementsByTagName("rating");
                for (var i = 0; i < rating.length; i++)
                    eval("document.forms[0].pr" + (i + 1) + ".item(" + rating.item(i).text + ").checked = true");
            }
            break;
    }
}

function calc() {
    var radios = document.getElementsByTagName('input');
    var sum = 0;
    for (var j = 0; j < radios.length; j++)
        for (var i = 0; i < radios.length; i++)
            if (radios[i].type == 'radio' && radios[i].checked && radios[i].name == ('pr' + j))
                sum += parseInt(radios[i].value, 10);
    var vdiv = document.getElementById("div2");

    sum = Math.floor(sum / 7 * 10) / 10;
    document.getElementById("answer").style.visibility = "visible";
    document.getElementById("answer").innerText = "Средний балл: " + sum;
}

function setMark(arg, value) {
    rating.item(arg).textContent = value;
    xmldoc.save("Data.xml");
}