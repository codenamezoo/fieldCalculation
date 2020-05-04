// function WSB(a1,a2, b1, b2, R, Z, I, n) // for a direct input use. 
function WSB(form) // for a form type input use. 
{
    var unit = 1e-3;
    var a1 = form.a1.value * unit; // for a form type input use. 
    var a2 = form.a2.value * unit; // for a form type input use.  
    var b1 = form.b1.value * unit; // for a form type input use. 
    var b2 = form.b2.value * unit; // for a form type input use. 
    var R = form.R.value * unit; // for a form type input use. 
    var Z = form.Z.value * unit; // for a form type input use. 
    var I = form.I.value; // for a form type input use. 
    var n = form.n.value; // for a form type input use. 

    var Bz = 0;
    var Br = 0;
    var a_divide = 200;
    var th_divide = 180;
	var da = (a2 - a1) / a_divide;
	var dth = Math.PI / th_divide;
	var dI = n * I / ((a2 - a1) * (b2 - b1));
	var z1 = Z - b1;
	var z2 = Z - b2;
	var z12 = Math.pow(z1, 2);
	var z22 = Math.pow(z2, 2);
	var cos_th = [];
    var R2 = Math.pow(R, 2);
    // coefficient = 2 * (mu0 / 4 / Math.PI * dI * dth * da) = 2 * dI * dth * da * 1.0e-7
    var coeff = 2 * dI * dth * da * 1.0e-7;

	for (var j = 0; j < th_divide; j++)
	{
		cos_th.push(Math.cos(j * dth + dth / 2));
	}

	for(var i = 0; i < a_divide; i++)
	{
		var a_i = a1 + i * da + da/2;
		var a_i2 = Math.pow(a_i, 2);
		
		for (var j = 0; j < th_divide; j++)
		{
			var ai2_2Raicosth_R2 = a_i2 - 2 * R * a_i * cos_th[j] + R2;
			Bz += (a_i * (a_i - R * cos_th[j]) / (ai2_2Raicosth_R2))
                * ((z1 / Math.sqrt(ai2_2Raicosth_R2 + z12)) - (z2 / Math.sqrt(ai2_2Raicosth_R2 + z22)));
            Br += (a_i* cos_th[j])
                * ((1 / Math.sqrt(ai2_2Raicosth_R2 + z22)) - (1 / Math.sqrt(ai2_2Raicosth_R2 + z12)));
        }
    }
    Bz *= coeff;
    Br *= coeff;

    // form.BzDisp.value = Bz; // for a form type input use. 
    // form.BrDisp.value = Br; // for a form type input use. 
    form.BzDisp.value = Bz.toFixed(4); // for a form type input use. And we only use 4 digits.
    form.BrDisp.value = Br.toFixed(4); // for a form type input use. And we only use 4 digits. 

	return [Bz, Br];
}
/*
Copyright 2020 Wooseung Lee (wooseung@mit.edu)

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the Software
    is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
    OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/