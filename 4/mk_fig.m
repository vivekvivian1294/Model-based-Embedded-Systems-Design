function figH = mk_fig()
     figurePos = [50 50 50 50];
     figH = figure('Visible','off',...
	     'Name','Toggle',...
	     'Position',figurePos,...
	     'Resize','on',...
             'MenuBar','none');
    % Make figure visible after adding all components
    figH.Visible = 'on';
end