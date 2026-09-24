/*
** SampaLX web launcher (pre-js).
**
** fractol needs a fractal type as its first argument, which does not exist
** in the browser. This shim forwards the `?args=` query string to main() so
** the WebGL build can be driven from the URL, e.g.:
**
**   fractol.html?args=mandelbrot
**   fractol.html?args=julia,-0.7,0.27015
**   fractol.html?args=burning_ship
**   fractol.html?args=mandelbrot3d,2.0
**   fractol.html?args=julia3d,-0.7,0.27015,0.0
**
** Without `?args=`, it falls back to the Mandelbrot set.
*/
(function ()
{
	var	query;
	var	args;
	var	module;

	module = (typeof Module !== 'undefined') ? Module : {};
	query = new URLSearchParams(window.location.search);
	args = query.get('args');
	if (args)
		module['arguments'] = args.split(',');
	else
		module['arguments'] = ['mandelbrot'];
})();
